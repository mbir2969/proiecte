using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Data;
using log4net;
using Lab3.model;
using tasks.repository;

namespace Lab3.repository
{

    public class RepositoryParticipantDB : Repository<int, Participant>
    {
        private static readonly ILog logger = LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        IDictionary<String, string> props;

        public RepositoryParticipantDB(IDictionary<string, string> props)
        {
            logger.Info("Initializing repository participanti task.");
            this.props = props;
        }

        public void add(Participant elem)
        {
            logger.InfoFormat("Saving task: {0}.", elem.ToString());
            var connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText =
                    "insert into Participanti (nume, varsta, numarProbe) values (@nume, @varsta, @numarProbe)";
                var paramNume = command.CreateParameter();
                paramNume.ParameterName = "@nume";
                paramNume.Value = elem.getNume();
                command.Parameters.Add(paramNume);

                var paramVarsta = command.CreateParameter();
                paramVarsta.ParameterName = "@varsta";
                paramVarsta.Value = elem.getVarsta().ToString();
                command.Parameters.Add(paramVarsta);

                var paramNumarProbe = command.CreateParameter();
                paramNumarProbe.ParameterName = "@numarProbe";
                paramNumarProbe.Value = elem.getNumarProbe();
                command.Parameters.Add(paramNumarProbe);

                var result = command.ExecuteNonQuery();
                logger.InfoFormat("Saved {0} instances.", result);   

            }
            logger.InfoFormat("Instance {0} was saved.", elem.ToString());
        }

        public void delete(int id)
        {
            logger.InfoFormat("Deleting task {0}.", id.ToString());
            IDbConnection connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "delete from Participanti where id=@id";
                IDbDataParameter paramId = command.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                command.Parameters.Add(paramId);
                var result = command.ExecuteNonQuery();
                
                logger.InfoFormat("Deleted {0} instances.", result);
            }
            logger.InfoFormat("Instance with id {0} was deleted.", id.ToString());
        }

        public void update(Participant elem, int id)
        {
            logger.InfoFormat("Updating task {0}.", elem.ToString());
            IDbConnection connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText =
                    "update Participanti set nume = @nume, varsta = @varsta, numarProbe = @numarProbe where id = @id";
                IDbDataParameter paramNume = command.CreateParameter();
                paramNume.ParameterName = "@nume";
                paramNume.Value = elem.getNume();
                command.Parameters.Add(paramNume);
                
                IDbDataParameter paramVarsta = command.CreateParameter();
                paramVarsta.ParameterName = "@varsta";
                paramVarsta.Value = elem.getVarsta();
                command.Parameters.Add(paramVarsta);
                
                IDbDataParameter paramNumarProbe = command.CreateParameter();
                paramNumarProbe.ParameterName = "@numarProbe";
                paramNumarProbe.Value = elem.getNumarProbe();
                command.Parameters.Add(paramNumarProbe);
                
                IDbDataParameter paramId = command.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                command.Parameters.Add(paramId);

                var result = command.ExecuteNonQuery();
                
                logger.InfoFormat("Updated {0} instances.", result);
            }

            logger.InfoFormat("Instance {0} was updated.", elem.ToString());
        }

        public Participant findById(int id)
        {
            logger.InfoFormat("Finding one task.");
            IDbConnection connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "select * from Participanti where id = @id";
                IDbDataParameter paramId = command.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                command.Parameters.Add(paramId);

                using (var result = command.ExecuteReader())
                {
                    if (result.Read())
                    {
                        String nume = result.GetString(1);
                        CategorieVarsta.TryParse(result.GetString(2), out CategorieVarsta varsta);
                        int numarProbe = result.GetInt32(3);
                        Participant participant = new Participant(nume, varsta, numarProbe);
                        participant.setID(id);
                        logger.InfoFormat("Instance with id {0} was found", id.ToString());
                        return participant;
                    }
                }
            }
            logger.InfoFormat("No instance with id {0} was found.", id.ToString());
            return null;
        }

        public IEnumerable<Participant> findAll()
        {
            logger.InfoFormat("Finding all task.");
            IDbConnection connection = DBUtils.getConnection(props);
            IList<Participant> participanti = new List<Participant>();
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "select * from Participanti";

                using (var result = command.ExecuteReader())
                {
                    while (result.Read())
                    {
                        int id = result.GetInt32(0);
                        String nume = result.GetString(1);
                        CategorieVarsta.TryParse(result.GetString(2), out CategorieVarsta varsta);
                        int numarProbe = result.GetInt32(3);

                        Participant participant = new Participant(nume, varsta, numarProbe);
                        participant.setID(id);
                        participanti.Add(participant);
                    }
                }
            }
            logger.InfoFormat("{0} instances found.", participanti.Count.ToString());
            return participanti;
        }

        public Collection<Participant> getAll()
        {
            logger.InfoFormat("Getting all task.");
            IDbConnection connection = DBUtils.getConnection(props);
            Collection<Participant> participanti = new Collection<Participant>();
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "select * from Participanti";

                using (var result = command.ExecuteReader())
                {
                    while (result.Read())
                    {
                        int id = result.GetInt32(0);
                        String nume = result.GetString(1);
                        CategorieVarsta.TryParse(result.GetString(2), out CategorieVarsta varsta);
                        int numarProbe = result.GetInt32(3);

                        Participant participant = new Participant(nume, varsta, numarProbe);
                        participant.setID(id);
                        participanti.Add(participant);
                    }
                }
            }
            logger.InfoFormat("{0} instances found.", participanti.Count.ToString());
            return participanti;
        }
    }
}